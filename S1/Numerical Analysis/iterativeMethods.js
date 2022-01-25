/*	Iterative methods for solving systems of linear equations
	Part of the numerical analysis course taught at the ENSET Mohammedia superior school
	Based on the third chapter of the textbook provided by professor Ahmed Tadlaoui
	Made by Youssef BEN SADIK (GLSID 2021-2024)
 */

// Jacobi Method
const Jacobi = (A, b, init, iterationsNumber) => {
	iterations = [init]
	for (let k = 1; k <= iterationsNumber; k++) {
		iterations[k] = new Array()
		for (let i = 0; i < A.length; i++) {
			let sum = 0
			for (let j = 0; j < A.length; j++)
				if (j !== i) sum += A[i][j] * iterations[k - 1][j]
			iterations[k][i] = (1 / A[i][i]) * (b[i] - sum)
		}
	}
	return iterations
}

// Gauss-Seidel Method
const GaussSeidel = (A, b, init, iterationsNumber) => {
	iterations = [init]
	for (let k = 1; k <= iterationsNumber; k++) {
		iterations[k] = new Array()
		for (let i = 0; i < A.length; i++) {
			let sum1 = 0,
				sum2 = 0
			for (let j = 0; j < i; j++) sum1 += A[i][j] * iterations[k][j]
			for (let j = i + 1; j < A.length; j++)
				sum2 += A[i][j] * iterations[k - 1][j]
			iterations[k][i] = (1 / A[i][i]) * (b[i] - sum1 - sum2)
		}
	}
	return iterations
}

// DRIVER CODE

/* The System of Linear Equations we are testing:
        4x₁ -x₂        = 6
        -x₁ + 4x₂ -x₃  = 4
            -x₂ + 4x₃  = 6
    
    Ax = b  <=>

    A =      4  -1   0        b = {6, 4, 6}
            -1   4  -1
             0  -1   4
*/

const jacobiIterations = Jacobi(
	// The matrix A :
	[
		[+4, -1, +0],
		[-1, +4, -1],
		[+0, -1, +4],
	],
	// The vector b :
	[/* b₁ = */ 6, /* b₂ = */ 4, /* b₃ = */ 6],
	// Initial guess :
	[/* x₁⁽⁰⁾ = */ 0, /* x₂⁽⁰⁾ = */ 0, /* x₃⁽⁰⁾ = */ 0],
	/* Number of iterations : */ 20
)

const gaussSeidelIterations = GaussSeidel(
	// The matrix A :
	[
		[+4, -1, +0],
		[-1, +4, -1],
		[+0, -1, +4],
	],
	// The vector b :
	[/* b₁ = */ 6, /* b₂ = */ 4, /* b₃ = */ 6],
	// Initial guess :
	[/* x₁⁽⁰⁾ = */ 0, /* x₂⁽⁰⁾ = */ 0, /* x₃⁽⁰⁾ = */ 0],
	/* Number of iterations : */ 20
)

console.log(`\nIterations of Jacobi method: \n`)
console.table(jacobiIterations)
console.log(`\nIterations of Gauss-Siedel method: \n`)
console.table(gaussSeidelIterations)
