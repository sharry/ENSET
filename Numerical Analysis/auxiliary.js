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

const printPolynomial = (poly) => {
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
		else coeff = Math.abs(poly[i]).toString()
		if (poly[i] !== 0) str += sign + coeff + x
	}
	console.log(str)
}

module.exports = {
	subscript,
	superscript,
	formatMatrixRow,
	printPolynomial,
}
