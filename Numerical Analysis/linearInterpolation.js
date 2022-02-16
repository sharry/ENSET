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

// Lagrange Method
// Lᵢ(x) = ₍ⱼ₌₀, ⱼ≠ᵢ₎∏ⁿ (x - xⱼ)/(xᵢ - xⱼ)
// P(x) = ᵢ₌₀Σⁿ yᵢ Lᵢ(x)

const Lagrange = (Xs, Ys) => {
	const n = Xs.length
	let tmp = []
	let L = []
	for (let i = 0; i < n; i++) {
		let l = []
		for (let j = 0; j < n; j++) {
			if (j !== i) {
				const denom = Xs[i] - Xs[j]
				l.push(1 / denom)
				l.push((-1 * Xs[j]) / denom)
				tmp.push(l)
				l = []
			}
		}
		L.push(aux.multiply(tmp[2 * i], tmp[2 * i + 1]))
	}
	P = []
	for (let i = 0; i < n; i++) {
		let sum = 0
		for (let j = 0; j < n; j++) {
			sum += Ys[j] * L[j][i]
			L[j][i] = parseFloat(L[j][i].toFixed(2))
		}
		P.push(parseFloat(sum.toFixed(2)))
	}
	return { L: L, P: P }
}

// Newton divided differences Method

// f(xᵢ) = yᵢ | i = 0, 1, ..., n
// 1ˢᵗ divided difference:
// f(xᵢ, xⱼ) = (f(xⱼ) - f(xᵢ)) / (xⱼ - xᵢ)
// 2ⁿᵈ divided difference:
// f(xᵢ, xⱼ, xₖ) = (f(xⱼ, xₖ) - f(xᵢ, xⱼ)) / (xₖ - xᵢ)
// ...
// nᵗʰ divided difference:
// f(xᵢ, xⱼ, xₖ, ..., xₙ) = (f(xⱼ, xₖ, ..., xₙ) - f(xᵢ, xⱼ, ..., xₙ₋₁)) / (xₙ - xᵢ)
/*
Example: With 3 data pairs (x₀, y₀), (x₁, y₁), (x₂, y₂)
┌──────┬────────┬───────────────────────┬───────────────────────────────┐
│  xᵢ  │  f(xᵢ) │      f(xᵢ, xᵢ₊₁)      │       f(xᵢ, xᵢ₊₁, xᵢ₊₂)       │
├──────┼────────┼───────────────────────┼───────────────────────────────┤
│  x₀  │   y₀   ├───────────────────────┤///////////////////////////////│
├──────┼────────┤ (f(x₁)-f(x₀))/(x₁-x₀) ├───────────────────────────────┤
│  x₁  │   y₁   ├───────────────────────┤ (f(x₁, x₂)-f(x₀, x₁))/(x₂-x₀) │
├──────┼────────┤ (f(x₂)-f(x₁))/(x₂-x₁) ├───────────────────────────────┤
│  x₂  │   y₂   ├───────────────────────┤///////////////////////////////│
└──────┴────────┴───────────────────────┴───────────────────────────────┘

	P(x) = y₀ + f(x₁, x₂) (x - x₀) + f(x₀, x₁, x₂) (x - x₁)

*/

Newton = (Xs, Ys) => {}

// Cubic Splines Method

// Tests

const x = [0, 2 / 3, 1]
const y = [1, 1 / 2, 0]

console.log('Vandermonde matrix method: ')
aux.printPolynomial(vandermonde(x, y))

console.log('\nLagrange method:\n')
const Ls = Lagrange(x, y).L
for (let i = 0; i < Ls.length; i++) {
	aux.printPolynomial(Ls[i], 'L' + aux.subscript(i) + '(x) = ')
}
aux.printPolynomial(Lagrange(x, y).P, '\nP = ')
