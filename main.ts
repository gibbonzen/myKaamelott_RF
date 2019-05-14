import { Logger, Color } from "./tools/logger";
import { MasterNode } from "./master_module/master-node";
import { ProtocoleRadio } from "./common/network/protocole-radio";
import { DoorNode } from "./door_module/door-node";
import { RadioEvent } from "./common/event/radio-event";

class Main {
    
    constructor(parameters) {
        Logger.log("Start program", this, Color.FG_RED)
        
        // Init network
        // Create radio networking
        let radioNet = new ProtocoleRadio()
        
        // Init nodes
        // Create master module
        let masterNode = new MasterNode(0)
        masterNode.setRadioNetwork(radioNet)
        
        
        // Create Door module
        let doorNode = new DoorNode(1)
        doorNode.setRadioNetwork(radioNet)
        
        
        // Simulation
        masterNode.emitOnRadio(new RadioEvent(masterNode, "Test radio message 2"))
        
        
    }
}

new Main([])