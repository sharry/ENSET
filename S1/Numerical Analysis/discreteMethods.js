/*	Discrete methods to solve a system of linear equations
	Part of the numerical analysis course taught at the ENSET Mohammedia superior school
	Based on the second chapter of the textbook provided by professor Ahmed Tadlaoui
	Made by Youssef BEN SADIK (GLSID 2021-2024)
 */

const aux = require('./auxiliary')

// 1) Gaussian elimination

// Takes an augmented matrix and return the solution (assumes finite solution)
const gauss = (aug) => {
	for (let i = 0; i < aug.length; i++) {
		// Get the pivot row
		pivot = Math.abs(aug[i][i])
		pivotRow = i
		for (let j = i + 1; j < aug.length; j++) {
			if (Math.abs(aug[j][i]) > pivot) {
				pivot = aug[j][i]
				pivotRow = j
			}
		}
		// Swap the current with the pivot row
		for (let j = i; j <= aug.length; j++) {
			let tmp = aug[pivotRow][j]
			aug[pivotRow][j] = aug[i][j]
			aug[i][j] = tmp
		}
		// Row-echelon form
		for (let j = i + 1; j < aug.length; j++) {
			let c = aug[j][i] / aug[i][i]
			for (let k = i; k <= aug.length; k++) {
				aug[j][k] -= c * aug[i][k]
			}
		}
	}
	let zeros = []
	// Solve the system
	for (let i = aug.length - 1; i >= 0; i--) {
		zeros[i] = aug[i][aug.length] / aug[i][i]
		for (let j = i - 1; j >= 0; j--) {
			aug[j][aug.length] -= aug[j][i] * zeros[i]
		}
	}

	return zeros.map((e) => Number(e.toFixed(2)) + 0)
}

// 2) LU decomposition

// Decompose a matrix into LU with: A = LU
const LU = (matrix) => {
	// If the matrix is augmented remove last column
	if (matrix.length !== matrix[0].length)
		matrix = matrix
			.slice()
			.map((e) => e.slice())
			.map((e) => e.slice(0, -1))
	// Clone matrix into B
	let B = matrix.slice().map((e) => e.slice())
	for (let i = 0; i < matrix.length; i++) {
		for (let j = i + 1; j < matrix.length; j++) {
			let c = matrix[j][i] / matrix[i][i]
			B[j][i] = c
			for (let k = i; k < matrix.length; k++) {
				matrix[j][k] -= c * matrix[i][k]
			}
		}
	}
	for (let i = 0; i < B.length; i++) {
		for (let j = 0; j < B.length; j++) {
			// Set the diagonal to 1's
			if (i === j) B[i][j] = 1
			//Set non diagonal and upper triangle to 0's
			else if (i < j) B[i][j] = 0
		}
	}
	return { Upper: matrix, Lower: B }
}

// Tests

/* The System of Linear Equations we are testing:
        x₁ + x₂ + 3x₄ = 4
        2x₁ + x₂ - x₃ + x₄ = 1
        3x₁ - x₂ - x₃ + 2x₄ = -3
        -x₁ + 3x₂ + 3x₃ - x₄ = 3
*/

// The augmented matrix correspondant to the system of linear equations
let augmentedMatrix = [
	[+1, +1, +0, +3, +4],
	[+2, +1, -1, +1, +1],
	[+3, -1, -1, +2, -3],
	[-1, +2, +3, -1, +4],
]

// Ax = b
const A = augmentedMatrix
	.slice()
	.map((e) => e.slice())
	.map((e) => e.slice(0, -1))
const b = augmentedMatrix
	.slice()
	.map((e) => e.slice())
	.map((e) => e.pop())

//Gaussian method test
console.log(
	`Gaussian Method:\nSolution Set = {${gauss(augmentedMatrix).map(
		(e, i) => ` x${aux.subscript(i + 1)} = ${e}`
	)} }\n\n`
)

// LU decomposition test
const lower = LU(A).Lower
console.log(
	'LU decomposition:\n\nL =\n' +
		lower.map((d) => '\t' + d.join('\t')).join('\n\n')
)
const upper = LU(A).Upper
console.log('\nU = \n' + upper.map((d) => '\t' + d.join('\t')).join('\n\n'))
const y = aux.solveLower(lower, b)
const x = aux.solveUpper(upper, y)
// Ax = b <=>	Ly = b
// 				Ux = y
console.log(
	`\nSolution set: {${x.map((e, i) => ` x${aux.subscript(i + 1)} = ${e}`)} }`
)
