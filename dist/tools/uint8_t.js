"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class uint8_t extends Number {
    constructor(radix = 0) {
        super();
        if (this.isByte(radix))
            this.radix = radix;
        else
            throw new NotByteValueError(`${radix} is not a uint8_t valid value.`);
    }
    isByte(radix) {
        return radix > -255 && radix < 256;
    }
    valueOf() {
        return this.radix;
    }
    toString() {
        return this.radix.toString();
    }
}
exports.uint8_t = uint8_t;
class NotByteValueError extends Error {
    constructor(msg) {
        super(msg);
    }
}
exports.NotByteValueError = NotByteValueError;
//# sourceMappingURL=uint8_t.js.map