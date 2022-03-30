Array.prototype.hasOperator = function () {
	return (
		this.includes('+') ||
		this.includes('-') ||
		this.includes('*') ||
		this.includes('/')
	)
}

const mainScreen = document.getElementById('main-screen')
const preResultScreen = document.getElementById('pre-result')
let inputs = []
loi = 0

const reset = () => {
	inputs = []
	mainScreen.innerHTML = ''
	preResultScreen.innerHTML = ''
	loi = 0 // last operator index
}

document.addEventListener(
	'keydown',
	(event) => {
		switch (event.key) {
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
			case '.':
			case '=':
			case '+':
			case '-':
			case '*':
			case '/':
			case 'Backspace':
			case 'Enter':
				buttonClick(event.key)
				break
			case 'Escape':
				reset()
		}
	},
	false
)

document.getElementById('backspace').addEventListener('long-press', () => {
	reset()
})

const buttonClick = (e) => {
	switch (e) {
		case 'Backspace':
			inputs.pop()
			break
		case '+':
		case '-':
			if (operatorAllowed()) {
				inputs.push(e)
				loi = inputs.length - 1
			}
			break
		case '*':
		case '/':
			if (operatorAllowed() && inputs.length != 0) {
				inputs.push(e)
				loi = inputs.length - 1
			}
			break
		case '.':
			if (inputs.length < 10 && !inputs.includes('.', loi, inputs.length)) {
				inputs.push(e)
			}
			break
		case '=':
		case 'Enter':
			if (inputs.length > 0) {
				preResultScreen.innerHTML = ''
				const res = evaluate()
				inputs = []
				inputs.push(res)
			}
			break
		default:
			if (inputs.length < 10) inputs.push(e)
			break
	}
	renderInputs()
	renderPreResult()
}
const renderInputs = () => {
	mainScreen.innerHTML = ''
	inputs.forEach((e) => {
		if (e == '/') mainScreen.innerHTML += '÷'
		else if (e == '*') mainScreen.innerHTML += '×'
		else mainScreen.innerHTML += e
	})
}
const renderPreResult = () => {
	try {
		if (inputs.hasOperator()) {
			preResultScreen.innerHTML = evaluate()
		}
	} catch (error) {
		preResultScreen.innerHTML = ''
	}
}
const operatorAllowed = () =>
	inputs.length < 9 &&
	inputs[inputs.length - 1] != '+' &&
	inputs[inputs.length - 1] != '-' &&
	inputs[inputs.length - 1] != '*' &&
	inputs[inputs.length - 1] != '/' &&
	inputs[inputs.length - 1] != '.'

function evaluate() {
	const hasOperatorAtEnd = ['+', '-', '*', '/'].includes(inputs.at(-1))
	const sliced = inputs.slice(0, inputs.length - 1)
	if (hasOperatorAtEnd && sliced.hasOperator()) {
		let ev = eval(sliced.join(''))
		if (ev.toString().length > 10) {
			if (parseInt(ev).toString().length > 10) {
				return 'Range exceeded'
			}
			ev = toPrecision(ev, 10 - parseInt(ev).toString().length)
		}
		return ev
	}
	let ev = eval(inputs.join(''))
	if (ev.toString().length > 10) {
		if (parseInt(ev).toString().length > 10) {
			return 'Range exceeded'
		}
		ev = toPrecision(ev, 10 - parseInt(ev).toString().length)
	}
	return ev
}

function toPrecision(num, precision) {
	const factor = Math.pow(10, precision)
	return Math.round(num * factor) / factor
}
