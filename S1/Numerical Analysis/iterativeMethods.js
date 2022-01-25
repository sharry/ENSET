/*	Iterative methods for solving systems of linear equations
	Part of the numerical analysis course taught at the ENSET Mohammedia superior school
	Based on the third chapter of the textbook provided by professor Ahmed Tadlaoui
	Made by Youssef BEN SADIK (GLSID 2021-2024)
 */

// Jacobi Method
//  xᵢ⁽ᵏ⁺¹⁾ = (1 / aᵢᵢ) × (bᵢ - ⱼ≠ᵢΣ aᵢⱼ xⱼ⁽ᵏ⁾)
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
//  xᵢ⁽ᵏ⁺¹⁾ = (1 / aᵢᵢ) × (bᵢ - ⱼ₌₁Σⁱ⁻¹ aᵢⱼ xⱼ⁽ᵏ⁺¹⁾ - ⱼ₌ᵢ₊₁Σⁿ aᵢⱼ xⱼ⁽ᵏ⁾)
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

// Strictly dominant diagonal
// |aᵢᵢ| > ⱼ≠ᵢΣ|aᵢⱼ| ; ∀i ∈ {1, ..., n}
const hasStrictlyDominantDiagonal = (matrix) => {
	for (let i = 0; i < matrix.length; i++) {
		let diagonal = Math.abs(matrix[i][i])
		let sum = 0
		for (let j = 0; j < matrix.length; j++) {
			if (j !== i) sum += Math.abs(matrix[i][j])
		}
		if (sum >= diagonal) return false
	}
	return true
}

// DRIVER CODE

/* The System of Linear Equations we are testing:
        4x₁ -x₂        = 6
        -x₁ + 4x₂ -x₃  = 4
            -x₂ + 4x₃  = 6
    
      Ax = b :
            ┌           ┐
            │ 4  -1   0 │       
      A =   │-1   4  -1 │  ;  b = [6, 4, 6]
            │ 0  -1   4 │
            └           ┘
*/

// Check if the Jacobi and Gauss-Seidel methods are converging
if (
	hasStrictlyDominantDiagonal([
		[+4, -1, +0],
		[-1, +4, -1],
		[+0, -1, +4],
	])
) {
	console.log(
		'\nThe matrix has a strictly dominant diagonal.\n' +
			'Hence, the Jacobi and Gauss-Seidel methods are converging.\n'
	)

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
}

/*

# Expected output


The matrix has a strictly dominant diagonal.
Hence, the Jacobi and Gauss-Seidel methods are converging.

Iterations of Jacobi method: 

┌─────────┬────────────────────┬────────────────────┬────────────────────┐
│         │         x₁         │         x₂         │         x₃         │
├─────────┼────────────────────┼────────────────────┼────────────────────┤
│    0    │         0          │         0          │         0          │
│    1    │        1.5         │         1          │        1.5         │
│    2    │        1.75        │        1.75        │        1.75        │
│    3    │       1.9375       │       1.875        │       1.9375       │
│    4    │      1.96875       │      1.96875       │      1.96875       │
│    5    │     1.9921875      │      1.984375      │     1.9921875      │
│    6    │     1.99609375     │     1.99609375     │     1.99609375     │
│    7    │    1.9990234375    │    1.998046875     │    1.9990234375    │
│    8    │   1.99951171875    │   1.99951171875    │   1.99951171875    │
│    9    │  1.9998779296875   │   1.999755859375   │  1.9998779296875   │
│   10    │  1.99993896484375  │  1.99993896484375  │  1.99993896484375  │
│   11    │ 1.9999847412109375 │ 1.999969482421875  │ 1.9999847412109375 │
│   12    │ 1.9999923706054688 │ 1.9999923706054688 │ 1.9999923706054688 │
│   13    │ 1.9999980926513672 │ 1.9999961853027344 │ 1.9999980926513672 │
│   14    │ 1.9999990463256836 │ 1.9999990463256836 │ 1.9999990463256836 │
│   15    │ 1.999999761581421  │ 1.9999995231628418 │ 1.999999761581421  │
│   16    │ 1.9999998807907104 │ 1.9999998807907104 │ 1.9999998807907104 │
│   17    │ 1.9999999701976776 │ 1.9999999403953552 │ 1.9999999701976776 │
│   18    │ 1.9999999850988388 │ 1.9999999850988388 │ 1.9999999850988388 │
│   19    │ 1.9999999962747097 │ 1.9999999925494194 │ 1.9999999962747097 │
│   20    │ 1.9999999981373549 │ 1.9999999981373549 │ 1.9999999981373549 │
└─────────┴────────────────────┴────────────────────┴────────────────────┘

Iterations of Gauss-Siedel method:

┌─────────┬────────────────────┬────────────────────┬────────────────────┐
│         │         x₁         │         x₂         │         x₃         │
├─────────┼────────────────────┼────────────────────┼────────────────────┤
│    0    │         0          │         0          │         0          │
│    1    │        1.5         │       1.375        │      1.84375       │
│    2    │      1.84375       │      1.921875      │     1.98046875     │
│    3    │     1.98046875     │    1.990234375     │   1.99755859375    │
│    4    │   1.99755859375    │   1.998779296875   │  1.99969482421875  │
│    5    │  1.99969482421875  │ 1.999847412109375  │ 1.9999618530273438 │
│    6    │ 1.9999618530273438 │ 1.9999809265136719 │ 1.999995231628418  │
│    7    │ 1.999995231628418  │ 1.999997615814209  │ 1.9999994039535522 │
│    8    │ 1.9999994039535522 │ 1.9999997019767761 │ 1.999999925494194  │
│    9    │ 1.999999925494194  │ 1.999999962747097  │ 1.9999999906867743 │
│   10    │ 1.9999999906867743 │ 1.9999999953433871 │ 1.9999999988358468 │
│   11    │ 1.9999999988358468 │ 1.9999999994179234 │ 1.9999999998544808 │
│   12    │ 1.9999999998544808 │ 1.9999999999272404 │  1.99999999998181  │
│   13    │  1.99999999998181  │ 1.999999999990905  │ 1.9999999999977263 │
│   14    │ 1.9999999999977263 │ 1.9999999999988631 │ 1.9999999999997158 │
│   15    │ 1.9999999999997158 │ 1.999999999999858  │ 1.9999999999999645 │
│   16    │ 1.9999999999999645 │ 1.9999999999999822 │ 1.9999999999999956 │
│   17    │ 1.9999999999999956 │ 1.9999999999999978 │ 1.9999999999999996 │
│   18    │ 1.9999999999999996 │         2          │         2          │
│   19    │         2          │         2          │         2          │
│   20    │         2          │         2          │         2          │
└─────────┴────────────────────┴────────────────────┴────────────────────┘
*/
