import { TimerUtils } from "../TimerUtils/TimerUtils";

export class Clock {
    private zeroTime: number // Time on create new clock object in millis
    
    private hCount: number = 0
    private mCount: number = 0
    private sCount: number = 0

    constructor(time: string) { // time in format "hh:mm:ss"
        this.setTime(time)
    }

    setTime(time: string) {
        this.zeroTime = TimerUtils.superMillis()
        
        let timeUnits = time.split(":")
        let hour = timeUnits[0]
        let min = timeUnits[1]
        let sec = timeUnits[2]

        this.hCount = Number(hour) | 0
        this.mCount = Number(min) | 0
        this.sCount = Number(sec) | 0
    }

    process() {
        let timer = TimerUtils.superMillis() // millis
        
        if(timer % 1000 === 0) { // Each seconds
            this.sCount++
        }

        if(this.sCount >= 60) { // one minute
            this.mCount++;
            this.sCount = 0; // reinitiate seconds counter
        }

        if(this.mCount >= 60) { // one hour
            this.hCount++;
            this.mCount = 0;
        }

        if(this.hCount >= 24) { // one day
            this.hCount = 0
        }
    }

    // Return number of second from midnight
    getTime(): number {
        let hourSeconds = TimerUtils.convert(this.hCount, "h", "s")
        let minSeconds = TimerUtils.convert(this.mCount, "m", "s")
        return hourSeconds + minSeconds + this.sCount
    }

    toString() {
        return this.hCount.toLocaleString("fr-FR", { minimumIntegerDigits: 2 }) 
            + ":" + this.mCount.toLocaleString("fr-FR", { minimumIntegerDigits: 2 })
            + ":" + this.sCount.toLocaleString("fr-FR", { minimumIntegerDigits: 2 })
    }

}