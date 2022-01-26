/*	Numerical methods for solving equation f(x) = 0
	Part of the numerical analysis course taught at the ENSET Mohammedia superior school
	Based on the fourth chapter of the textbook provided by professor Ahmed Tadlaoui
	Made by Youssef BEN SADIK (GLSID 2021-2024)
 */

// Bisection method

const Bisection = (
	/* The function */ f,
	/* Interval left  extremity */ a,
	/* Interval right extremity */ b,
	/* Desired precision */ eps,
	/* Max iterations */ max
) => {
	// Make sure extremities well delivered
	if (a > b) {
		const tmp = a
		a = b
		b = tmp
	}
	let n = 0,
		p = 0
	while (n < max) {
		p = (a + b) / 2
		if (f(p) === 0 || (b - a) / 2 < eps) {
			return {
				/* Solution approximation */ p: p,
				/* Maximal error */ err: (b - a) / 2,
			}
		}
		if (f(a) * f(b) < 0) b = p
		else a = p
		n++
	}
	return {
		/* Solution approximation */ p: p,
		/* Maximal error */ err: (b - a) / 2,
	}
}

// Newton Method

const Newton = (
	/* The function f(x) */ f,
	/* The first derivative f'(x) */ fp,
	/* Initial approximation */ p0,
	/* Desired precision */ eps,
	/* Maximum number of iterations */ max
) => {
	let n = 0
	while (n < max) {
		const p = p0 - f(p0) / fp(p0)
		if (Math.abs(p - p0) < eps) return p
		p0 = p
		n++
	}
	return console.log(`Method failed after ${max} iterations`)
}

// Secant Method
const Secant = (
	/* The function f(x) */ f,
	/* Initial approximation */ p0,
	/* Initial approximation */ p1,
	/* Desired precision */ eps,
	/* Maximum number of iterations */ max
) => {
	let n = 0
	let q0 = f(p0)
	let q1 = f(p1)
	while (n < max) {
		const p = p1 - q1 * ((p1 - p0) / (q1 - q0))
		if (Math.abs(p - p1) < eps) {
			return p
		}
		p0 = p1
		q0 = q1
		p1 = p
		q1 = f(p)
		n++
	}
	return console.log(`Method failed after ${max} iterations`)
}

// Fixed-point Method
const FixedPoint = (
	/* The function g(x) = x: */ g,
	/* Initial approximation */ p0,
	/* Desired precision */ eps,
	/* Maximum number of iterations */ max
) => {
	let n = 0
	while (n < max) {
		const p = g(p0)
		if (Math.abs(p - p0) < eps) return p
		p0 = p
		n++
	}
	return console.log(`Method failed after ${max} iterations`)
}

// DRIVER CODE

// f(x) = tan(x) - x
function f(x) {
	return Math.tan(x) - x
}

const bisection = Bisection(f, 4.4, 4.5, 10 ** -3, 7)
console.log(
	`\n# Bisection Method:
	f(x) = tan(x) - x = 0 :
	α ≈ ${bisection.p}
	Maximal error: ${bisection.err}\n`
)

// g(x) = x³ - 3x - 1
const g = (x) => x ** 3 - 3 * x - 1
// g'(x) = 3x² - 3
const gp = (x) => 3 * x ** 2 - 3

const alpha = Newton(g, gp, 2, 10 ** -2, 5)
console.log(
	`\n# Newton Method:
	f(x) = x³ - 3x - 1 = 0 :
	α ≈ ${alpha}\n`
)

// h(x) = cos(x) + 2 sin(x) + x²
const h = (x) => Math.cos(x) + 2 * Math.sin(x) + x ** 2

const beta = Secant(h, 0, -0.1, 0.001, 100)
console.log(
	`\n# Secant Method:
	f(x) = cos(x) + 2 sin(x) + x² = 0 :
	α ≈ ${beta}\n`
)

// f(x) = cos(x) - 3x + 1 = 0
// g(x) = x <=> (cos(x) + 1) / 3 = x
const gx = (x) => (Math.cos(x) + 1) / 3

const gamma = FixedPoint(gx, 1, 0.000001, 10)
console.log(
	`\n# Fixed-point Method:
	f(x) = cos(x) + 3x + 1 = 0
	g(x) = x <=> (cos(x) + 1) / 3 = x
	α ≈ ${gamma}\n`
)
