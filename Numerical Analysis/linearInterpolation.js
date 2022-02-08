// Direct method
const mat = require('./matrices')
const aux = require('./auxiliary')
const vandermonde = (Xs, Ys) => {
	const n = Xs.length
	// vandermonde matrix:
	let matrix = new Array(n)
	for (let i = 0; i < n; i++) {
		matrix[i] = new Array(n)
		for (let j = 0; j < n; j++) {
			matrix[i][j] = Math.pow(Xs[i], n - j - 1)
		}
	}
	// Solving using Gaussian elimination
	const aug = mat.augment(matrix, Ys)
	mat.ref(aug)
	let zeros = []
	for (let i = aug.length - 1; i >= 0; i--) {
		zeros[i] = aug[i][aug.length] / aug[i][i]
		for (let j = i - 1; j >= 0; j--) {
			aug[j][aug.length] -= aug[j][i] * zeros[i]
		}
	}
	return zeros.map((e) => Number(e.toFixed(2)) + 0)
}

const polynomial = vandermonde([0, 1, 2], [1, 2, 5])
aux.printPolynomial(polynomial)

// Lagrange Method
// Lᵢ(x) = ₍ⱼ₌₀, ⱼ≠ᵢ₎∏ⁿ (x - xⱼ)/(xᵢ - xⱼ)
// P(x) = ᵢ₌₀Σⁿ yᵢ Lᵢ(x)

const x = [0, 1, 2]
const y = [1, 2, 5]

const Lagrange = (Xs, Ys, a) => {
	const n = Xs.length
	let P = 0
	for (let i = 0; i < n; i++) {
		let L = 1
		for (let j = 0; j < n; j++) {
			if (j !== i) L *= (a - Xs[j]) / (Xs[i] - Xs[j])
		}
		P += Ys[i] * L
	}
	return P
}

console.log(Lagrange(x, y, 3))
