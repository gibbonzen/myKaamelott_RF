import { Clock } from "./librairy/Clock/Clock";
import { CronTask } from "./librairy/CronTask/CronTask";

const clock = new Clock("16:00:00")
let lastClock = clock.getTime()

function initProgram() {
    let openCron = new CronTask("16:00:10", () => console.log("Coucou, c'est l'heure du petit déjeuné !"))
    openCron.attachTimer(clock)
    openCron.start()

    let closeCron = new CronTask("16:00:20", () => console.log("Il va faire tout noir !"))
    closeCron.attachTimer(clock)
    closeCron.start()

    let changeClock = new CronTask("16:00:30", () => {
        console.log("Le changement... c'est maintenant !")
        clock.setTime("16:00")
    })
    changeClock.attachTimer(clock)
    changeClock.start()
}

function program() {
    clock.process()

    getTime()
}


function getTime() {
    if(clock.getTime() !== lastClock) {
        lastClock = clock.getTime()
        console.log(clock.toString())
    }
}



//////////////////////
//        RUN       //

function setup() {
    initProgram()
}

function loop() {
    setTimeout(() => {
        program()
        loop()
    }, 0);
}

setup()
loop()