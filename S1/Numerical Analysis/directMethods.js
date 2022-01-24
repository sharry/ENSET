/*	Dicrect methods for solving systems of linear equations
	Part of the numerical analysis course taught at the ENSET Mohammedia superior school
	Based on the second chapter of the textbook provided by professor Ahmed Tadlaoui
	Made by Youssef BEN SADIK (GLSID 2021-2024)
 */

const aux = require('./auxiliary')
const mat = require('./matrices')

// 1) Gaussian elimination

// Takes an augmented matrix and return the solution (assumes finite solution)
const Gauss = (aug) => {
	// Get the row-echelon form of the augmented matrix
	let ref = mat.ref(aug)
	let zeros = []
	// Solve the system
	for (let i = aug.length - 1; i >= 0; i--) {
		zeros[i] = aug[i][aug.length] / aug[i][i]
		for (let j = i - 1; j >= 0; j--) {
			aug[j][aug.length] -= aug[j][i] * zeros[i]
		}
	}

	ref = ref.map((r) => r.map((e) => Number(e.toFixed(2)) + 0))
	return { zeros: zeros.map((e) => Number(e.toFixed(2)) + 0), ref: ref }
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

// 3) Gauss-Jordan Elimination

const GaussJordan = (aug) => {
	let ref = mat.ref(aug)
	// Reduced row-echelon form
	for (let i = ref.length - 1; i > 0; i--) {
		for (let j = i - 1; j >= 0; j--) {
			let c = ref[j][i] / ref[i][i]
			ref[j][i] -= c * ref[i][i]
			ref[j][ref.length] -= c * ref[i][ref.length]
		}
	}
	for (let i = 0; i < ref.length; i++) {
		ref[i][ref.length] /= ref[i][i]
		ref[i][i] = 1
	}
	let reducedRef = ref.map((e) => e.map((e) => Number(e.toFixed(2)) + 0))
	let zeros = []
	reducedRef.map((e) => zeros.push(e[ref.length]))
	return { reducedRef: reducedRef, zeros: zeros }
}

// Cholesky Elimination
const Cholesky = (matrix) => {
	if (mat.compare(matrix, mat.transpose(matrix)) === false)
		return console.log('This matrix is not symmetric')
	let l = matrix.slice().map((e) => e.slice())
	for (let i = 0; i < l.length; i++) {
		for (let j = 0; j < l.length; j++) {
			if (i === j) {
				let a = matrix[i][i]
				let sig = 0
				for (let k = 0; k < i; k++) {
					sig += l[i][k] * l[i][k]
				}
				l[i][i] = Math.sqrt(a - sig)
			} else if (i > j) {
				let d = 1 / l[j][j]
				let a = matrix[i][j]
				let sig = 0
				for (let k = 0; k < j; k++) {
					sig += l[i][k] * l[j][k]
				}
				l[i][j] = d * (a - sig)
			} else l[i][j] = 0
		}
	}
	return { L: l, tL: mat.transpose(l) }
}
// }

// DRIVER CODE

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
const gauss = Gauss([
	[+1, +1, +0, +3, +4],
	[+2, +1, -1, +1, +1],
	[+3, -1, -1, +2, -3],
	[-1, +2, +3, -1, +4],
])
console.log(
	'# Gaussian Method:\n\nRow-echelon form:\n' +
		gauss.ref.map((d) => '\t' + aux.formatMatrixRow(d)).join('\n\n')
)
console.log(
	`\nSolution Set = {${gauss.zeros.map(
		(e, i) => ` x${aux.subscript(i + 1)} = ${e}`
	)} }\n\n`
)

// LU decomposition test
const lower = LU(A).Lower
console.log(
	'# LU decomposition:\n\nL =\n' +
		lower.map((d) => '\t' + d.join('\t')).join('\n\n')
)
const upper = LU(A).Upper
console.log('\nU = \n' + upper.map((d) => '\t' + d.join('\t')).join('\n\n'))

// Ax = b <=>	Ly = b
// 				Ux = y
const y = mat.solveLower(lower, b)
console.log(`\ny = {${y.map((e, i) => ` y${aux.subscript(i + 1)} = ${e}`)} }`)
const x = mat.solveUpper(upper, y)
console.log(
	`Solution set: {${x.map((e, i) => ` x${aux.subscript(i + 1)} = ${e}`)} }`
)

// Gauss-Jordan method test

const gaussJordan = GaussJordan([
	[+1, +1, +0, +3, +4],
	[+2, +1, -1, +1, +1],
	[+3, -1, -1, +2, -3],
	[-1, +2, +3, -1, +4],
])

console.log(
	'\n\n# Gauss-Jordan Method:\n\nReduced row-echelon form:\n' +
		gaussJordan.reducedRef
			.map((d) => '\t' + aux.formatMatrixRow(d))
			.join('\n\n')
)
console.log(
	`\nSolution Set = {${gaussJordan.zeros.map(
		(e, i) => ` x${aux.subscript(i + 1)} = ${e}`
	)} }\n\n`
)

// Ax = b <=>	Ly = x
//				ᵗLx = y

const cholesky = Cholesky([
	[1, 1, 3],
	[1, 5, 5],
	[3, 5, 19],
])

console.log(
	'# Cholesky decomposition:\n\nL =\n' +
		cholesky.L.map((d) => '\t' + d.join('\t')).join('\n\n') +
		'\nᵗL = \n' +
		cholesky.tL.map((d) => '\t' + d.join('\t')).join('\n\n') +
		'\n\nWith ᵗL L = A'
)

const yp = mat.solveLower(cholesky.L, b)
const xp = mat.solveUpper(cholesky.tL, yp)
console.log(
	`Solution set: {${xp.map((e, i) => ` x${aux.subscript(i + 1)} = ${e}`)} }`
)
