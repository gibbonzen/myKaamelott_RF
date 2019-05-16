export class ClassTools {

    static getObjectClass(obj) {
		let objToStr = obj.toString()

		let isClazzObject = /class ([a-zA-Z]*) {.*/gi.exec(objToStr)
		if(isClazzObject !== null && [1] !== null) return isClazzObject[1]

		let isInstanceOf = /class ([a-zA-Z]*)/gi.exec(obj.constructor.toString())
		if(isInstanceOf !== null && [1] !== null) return isInstanceOf[1]

    return undefined;
	}
}