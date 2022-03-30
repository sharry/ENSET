const updateHeights = () => {
	const mondayScale = document.getElementById('monday-val').value
	const tuesdayScale = document.getElementById('tuesday-val').value
	const wednesdayScale = document.getElementById('wednesday-val').value
	const thursdayScale = document.getElementById('thursday-val').value
	const fridayScale = document.getElementById('friday-val').value
	const saturdayScale = document.getElementById('saturday-val').value
	const sundayScale = document.getElementById('sunday-val').value

	const mondayImage = document.getElementById('monday')
	const tuesdayImage = document.getElementById('tuesday')
	const wednesdayImage = document.getElementById('wednesday')
	const thursdayImage = document.getElementById('thursday')
	const fridayImage = document.getElementById('friday')
	const saturdayImage = document.getElementById('saturday')
	const sundayImage = document.getElementById('sunday')

	mondayImage.setAttribute('height', mondayScale)
	tuesdayImage.setAttribute('height', tuesdayScale)
	wednesdayImage.setAttribute('height', wednesdayScale)
	thursdayImage.setAttribute('height', thursdayScale)
	fridayImage.setAttribute('height', fridayScale)
	saturdayImage.setAttribute('height', saturdayScale)
	sundayImage.setAttribute('height', sundayScale)
}
const randomize = () => {
	document.getElementById('monday-val').value = Math.floor(Math.random() * 100)
	document.getElementById('tuesday-val').value = Math.floor(Math.random() * 100)
	document.getElementById('wednesday-val').value = Math.floor(
		Math.random() * 100
	)
	document.getElementById('thursday-val').value = Math.floor(
		Math.random() * 100
	)
	document.getElementById('friday-val').value = Math.floor(Math.random() * 100)
	document.getElementById('saturday-val').value = Math.floor(
		Math.random() * 100
	)
	document.getElementById('sunday-val').value = Math.floor(Math.random() * 100)

	updateHeights()
}

const reset = () => {
	document.getElementById('monday-val').value = 100
	document.getElementById('tuesday-val').value = 100
	document.getElementById('wednesday-val').value = 100
	document.getElementById('thursday-val').value = 100
	document.getElementById('friday-val').value = 100
	document.getElementById('saturday-val').value = 100
	document.getElementById('sunday-val').value = 100

	updateHeights()
}
