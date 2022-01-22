// convert numbers to subscript
const subscript = (num) => {
	const subs = ['₀', '₁', '₂', '₃', '₄', '₅', '₆', '₇', '₈', '₉']
	let str = num.toString()
	for (let i = 0; i < 10; i++) {
		str = str.replace(i.toString(), subs[i])
	}
	return str
}
// Multiply 2 matrices
const multiply = (A, B) => {
	var aNumRows = A.length,
		aNumCols = A[0].length,
		bNumCols = B[0].length,
		product = new Array(aNumRows)
	for (var i = 0; i < aNumRows; ++i) {
		product[i] = new Array(bNumCols)
		for (var j = 0; j < bNumCols; ++j) {
			product[i][j] = 0
			for (var k = 0; k < aNumCols; ++k) {
				product[i][j] += A[i][k] * B[k][j]
			}
		}
	}
	return product
}
// convert Ax = b to augmented matrix
const augment = (A, b) => {
	i = 0
	for (row of A) {
		row.push(b[i])
		i++
	}
	return A
}
// Solve triangular matrices
const solveUpper = (U, b) => {
	let zeros = []
	aug = augment(U, b)
	for (let i = aug.length - 1; i >= 0; i--) {
		zeros[i] = aug[i][aug.length] / aug[i][i]
		for (let j = i - 1; j >= 0; j--) {
			aug[j][aug.length] -= aug[j][i] * zeros[i]
		}
	}
	return zeros.map((e) => Number(e.toFixed(2)) + 0)
}
const solveLower = (L, b) => {
	let zeros = new Array(L.length)
	for (let i = 0; i < L.length; i++) {
		zeros[i] = b[i]
		for (let j = 0; j < i; j++) {
			zeros[i] -= zeros[j] * L[i][j]
		}
	}
	return zeros.map((e) => Number(e.toFixed(2)) + 0)
}

module.exports = {
	subscript: subscript,
	multiply: multiply,
	augment: augment,
	solveUpper: solveUpper,
	solveLower: solveLower,
}
