// convert numbers to subscript
const subscript = (num) => {
	const subs = ['₀', '₁', '₂', '₃', '₄', '₅', '₆', '₇', '₈', '₉']
	let str = num.toString()
	for (let i = 0; i < 10; i++) {
		str = str.replace(i.toString(), subs[i])
	}
	return str
}

const superscript = (num) => {
	const subs = ['⁰', '¹', '²', '³', '⁴', '⁵', '⁶', '⁷', '⁸', '⁹']
	let str = num.toString()
	for (let i = 0; i < 10; i++) {
		str = str.replace(i.toString(), subs[i])
	}
	return str
}

// Format for console.log
const formatMatrixRow = (row) => {
	var outStr = ''
	if (row.length === 1) {
		outStr = row[0]
	} else if (row.length === 2) {
		outStr = row.join('   |   ')
	} else if (row.length > 2) {
		outStr = row.slice(0, -1).join('     ') + '   |   ' + row.slice(-1)
	}
	return outStr
}

const printPolynomial = (poly, prefix = '') => {
	const n = poly.length
	let str = ''
	for (let i = 0; i < n; i++) {
		sign = poly[i] < 0 ? '-' : '+'
		if (i !== 0) sign = ' ' + sign + ' '
		if (i === 0 && poly[i] > 0) sign = ''
		x = ''
		if (n - i - 1 === 0) x = ''
		else if (n - i - 1 === 1) x += 'x'
		else x = 'x' + superscript(n - i - 1)
		coeff = ''
		if (poly[i] === 0) coeff = ''
		else if (poly[i] === 1 && i === n - 1) coeff = '1'
		else if (poly[i] === 1 && i !== n - 1) coeff = ''
		else coeff = fraction(Math.abs(poly[i]))

		if (coeff.includes('/')) coeff = '(' + coeff + ')'
		if (poly[i] !== 0) str += sign + coeff + x
	}
	console.log(prefix + str)
}

const gcd = (a, b) => {
	if (!b) return a
	a = parseInt(a)
	b = parseInt(b)
	return gcd(b, a % b)
}

const multiply = (A, B) => {
	const m = A.length
	const n = B.length
	var prod = []
	for (var i = 0; i < m + n - 1; i++) prod[i] = 0
	for (var i = 0; i < m; i++) {
		for (var j = 0; j < n; j++) prod[i + j] += A[i] * B[j]
	}
	return prod
}

const fraction = (number) => {
	let str = number.toString()
	let len = 0
	if (str.includes('.') && str.at(0) != '.') len = str.length - 2
	else if (str.includes('.') && str.at(0) == '.') len = str.length - 1
	else return number.toString()
	var denominator = Math.pow(10, len)
	var numerator = number * denominator
	const divisor = gcd(numerator, denominator)
	numerator /= divisor
	denominator /= divisor
	if (Math.abs(denominator) === 1 || Math.abs(denominator) === -1)
		return numerator.toFixed().toString()
	str = ''
	if (numerator < 0 || denominator < 0) {
		str += '-'
	}
	numerator = Math.abs(numerator.toFixed())
	denominator = Math.abs(denominator.toFixed())
	return str + numerator.toString() + '/' + denominator.toString()
}

module.exports = {
	subscript,
	superscript,
	formatMatrixRow,
	printPolynomial,
	fraction,
	gcd,
	multiply,
}
