// convert numbers to subscript
const subscript = (num) => {
	const subs = ['₀', '₁', '₂', '₃', '₄', '₅', '₆', '₇', '₈', '₉']
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

module.exports = {
	subscript,
	formatMatrixRow,
}
