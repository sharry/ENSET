const makeTable = (rows, cols) => {
	let res = '<table border="1">'
	for (let r = 0; r < rows; r++) {
		res += '<tr>'
		for (let c = 0; c < cols; c++) {
			res += '<td>'
			res += `(${r},${c})`
			res += '</td>'
		}
		res += '<tr>'
	}
	return (res += '</table>')
}

const showTable = () => {
	const cols = document.getElementById('cols')
	const rows = document.getElementById('rows')
	var myWindow = window.open('', 'MsgWindow')
	myWindow.document.write(makeTable(rows.value, cols.value))
}

const randomize = () => {
	const cols = document.getElementById('cols')
	const rows = document.getElementById('rows')
	cols.value = Math.floor(Math.random() * 50)
	rows.value = Math.floor(Math.random() * 50)
}
