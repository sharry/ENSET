let username
let birthdate

function test() {
	username = document.getElementById('username').value
	birthdate = document.getElementById('birthdate').value
	if (valid()) alert(`Hello ${username}, your birthdate is ${birthdate}`)
	else alert('Please fill all the fields correctly')
}

function valid() {
	if (username.length < 6) return false
	if (!username.match(/^[0-9A-Za-z]+$/)) return false
	if (birthdate.length == 0) return false
	return true
}
