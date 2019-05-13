import { DoorNode } from "./door_module/door-node";
import { Logger } from "./tools/logger";

class Main {
    private logger: Logger
    
    constructor(parameters) {
        console.log("Start program")

        this.logger = new Logger(this)

        // Create Door module
        let doorNode = new DoorNode(1)
    }
}

new Main([])