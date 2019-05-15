import { throws } from "assert";

export class uint8_t extends Number {
    private radix: number

    constructor(radix: number = 0) {
        super();
        if(this.isByte(radix))
            this.radix = radix
        else throw new NotByteValueError(`${radix} is not a uint8_t valid value.`)
    }

    private isByte(radix: number) {
        return radix > -255 && radix < 256
    }

    valueOf(): number {
        return this.radix
    }

    toString(): string {
        return this.radix.toString()
    }

}

export class NotByteValueError extends Error {
    constructor(msg: string) {
        super(msg)
    }
}