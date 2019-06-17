import { Clock } from "./Clock";

export class ClockObserver {
    private clock: Clock
    private time: number
    private listener: Function
    private started: boolean = false

    private delay: number = 10000 // 10 sec

    constructor(clock: Clock) {
        this.clock = clock;
    }

    onTime(time: number, listener: Function) {
        this.time = time
        this.listener = listener
    }

    private listen() {
        if(this.started) {
            setTimeout(() => {
                if(this.clock.getTime() == this.time) {
                    this.listener()

                    // stop a moment
                    this.stop()
                    setTimeout(() => {
                        this.start() // restart
                    }, this.delay);
                }

                this.listen()
            }, 0)
        }
    }

    start() {
        this.started = true
        this.listen()
    }

    stop() {
        this.started = false
    }

}