/* The System of Linear Equations:
        x₁ + x₂ + 3x₄ = 4
        2x₁ + x₂ - x₃ + x₄ = 1
        3x₁ - x₂ - x₃ + 2x₄ = -3
        -x₁ + 3x₂ + 3x₃ - x₄ = 3
*/

// Ax = b
let aug = [
	[+1, +1, +0, +3, +4],
	[+2, +1, -1, +1, +1],
	[+3, -1, -1, +2, -3],
	[-1, +2, +3, -1, +4],
]

// Gaussian elimination
const gauss = (aug) => {
	let zeros = []
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
	// Solve the system
	for (let i = aug.length - 1; i >= 0; i--) {
		zeros[i] = aug[i][aug.length] / aug[i][i]
		for (let j = i - 1; j >= 0; j--) {
			aug[j][aug.length] -= aug[j][i] * zeros[i]
		}
	}

	return zeros.map((e) => Number(e.toFixed(2)) + 0)
}

console.log(gauss(aug))
