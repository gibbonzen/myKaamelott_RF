import { Logger, Color } from "./tools/logger";
import { MasterNode } from "./master_module/master-node";
import { ProtocoleRadio } from "./common/network/protocole-radio";
import { DoorNode } from "./door_module/door-node";
import { RadioEvent } from "./common/event/radio-event";
import { uint8_t } from "./tools/uint8_t";
import { BirdTableNode } from "./bird-table_module/bird-table-node";

class Main {
    
    private radioNet: ProtocoleRadio
    private masterNode: MasterNode
    private doorNode: DoorNode
    private birdTableNode: BirdTableNode

    constructor(parameters) {
        Logger.log("Start program", this, Color.FG_RED)
        
        // Init network
        // Create radio networking
        this.radioNet = new ProtocoleRadio()
        
        // Init nodes
        // Create master module
        this.masterNode = new MasterNode(0b0000)
        this.masterNode.setRadioNetwork(this.radioNet)
        
        // Create Door module
        this.doorNode = new DoorNode(0b0001)
        this.doorNode.setRadioNetwork(this.radioNet)

        // Create bird table
        this.birdTableNode = new BirdTableNode(0b0010)
        this.birdTableNode.setRadioNetwork(this.radioNet)
        
        
        // Simulation
        this.runDoorSimulation()
        
    }

    private runDoorSimulation(): void {
        let data: uint8_t[] = this.getData()
        let event: RadioEvent = new RadioEvent(this.masterNode, this.doorNode, data)

        this.masterNode.emitOnRadio(event)

    }

    private getData(): uint8_t[] {
        let data: uint8_t[] = []
        for(let i = 0; i < 10; i++) {
            data.push(new uint8_t(i))
        }
        return data
    }

}

new Main([])