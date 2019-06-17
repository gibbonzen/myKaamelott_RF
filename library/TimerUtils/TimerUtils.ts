const SIMPLE_MULTIPLICATOR = 60
const SEC_MILLIS_MULTIPLICATOR = 1000

const DOWN_CONVERT = "*" // Hour to minutes or seconds
const UP_CONVERT = "/" // seconds to minutes or hour

export class TimerUtils {
    private static initialTimer: number = new Date().getTime()

    static superMillis(): number {
        return new Date().getTime() - this.initialTimer
    }

    static convert(time: number, from: string, to: string): number {
        let multiplicator = SIMPLE_MULTIPLICATOR
        let direction = DOWN_CONVERT

        switch(from) {
            case "h":
                direction = DOWN_CONVERT
                if(to === "s") multiplicator *= SIMPLE_MULTIPLICATOR // 60 * 60
                if(to === "ms") multiplicator *= SIMPLE_MULTIPLICATOR * SEC_MILLIS_MULTIPLICATOR // 60 * 60 * 1000
                break
            case "m":
                if(to === "h") direction = UP_CONVERT
                if(to === "ms") multiplicator *= SEC_MILLIS_MULTIPLICATOR // 60 * 1000
                break;
            case "s": 
                if(to === "h") {
                    direction = UP_CONVERT
                    multiplicator *= SIMPLE_MULTIPLICATOR // 60 * 60 
                }
                if(to === "ms") multiplicator = SEC_MILLIS_MULTIPLICATOR // 60 * 1000
                break 
            case "ms":
                direction = UP_CONVERT
                if(to === "s") multiplicator = SEC_MILLIS_MULTIPLICATOR // 1000
                if(to === "m") multiplicator *= SEC_MILLIS_MULTIPLICATOR // 60 * 1000
                if(to === "h") multiplicator *= SIMPLE_MULTIPLICATOR * SEC_MILLIS_MULTIPLICATOR // 60 * 60 * 1000
        }

        return direction === DOWN_CONVERT ? time * multiplicator : time / multiplicator;
    }

    static extractUnits(time: string): number[] {
        let timeUnits = time.split(":")
        let hour = Number(timeUnits[0]) | 0
        let min = Number(timeUnits[1]) | 0
        let sec = Number(timeUnits[2]) | 0
        return [ hour, min, sec ]
    }

}