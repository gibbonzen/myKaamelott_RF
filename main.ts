import { Logger, Color } from "./tools/logger";
import { MasterNode } from "./master_module/master-node";
import { ProtocoleRadio } from "./common/network/protocole-radio";
import { DoorNode } from "./door_module/door-node";
import { RadioEvent } from "./common/event/radio-event";
import { uint8_t } from "./tools/uint8_t";
import { BirdTableNode } from "./bird-table_module/bird-table-node";
import { EventTools } from "./tools/event-tools";
import { OpenCommand } from "./door_module/open-command";
import { Command } from "./common/node/command";
import { CloseCommand } from "./door_module/close-command";
import { FeedCommand } from "./bird-table_module/feed-command";
import { ProtocoleWifi } from "./common/network/protocole-wifi";
import { WifiEvent } from "./common/event/wifi-event";
import { NetworkNode } from "./common/node/network-node";

class Main {
    
    private wifiNet: ProtocoleWifi
    private radioNet: ProtocoleRadio
    private masterNode: MasterNode
    private doorNode: DoorNode
    private birdTableNode: BirdTableNode

    constructor(parameters) {
        Logger.log("Start program", this, Color.FG_RED)
        
        // Init network
        // Create radio networking
        this.radioNet = new ProtocoleRadio()
        
        // Create wifi networking
        this.wifiNet = new ProtocoleWifi()

        // Init nodes
        // Create master module
        this.masterNode = new MasterNode(0b0000)
        this.masterNode.setRadioNetwork(this.radioNet)
        this.masterNode.setWifiNetwork(this.wifiNet)
        
        // Create Door module
        this.doorNode = new DoorNode(0b0001)
        this.doorNode.setRadioNetwork(this.radioNet)

        // Create bird table
        this.birdTableNode = new BirdTableNode(0b0010)
        this.birdTableNode.setRadioNetwork(this.radioNet)
        
        
        // Simulation
        // Door sim
//        this.runDoorSimulation()

        // Wifi emul
        this.runWifiSimulation()
        
    }

    private runDoorSimulation(): void {
        let command: Command = new OpenCommand()
        let event: RadioEvent = new RadioEvent(this.masterNode, this.birdTableNode, command)
        this.masterNode.emitOnRadio(event)

        let sendEvent = () => this.masterNode.emitOnRadio(new RadioEvent(this.masterNode, this.doorNode, new CloseCommand()))
        this.delay(5000, sendEvent)

        sendEvent = () => this.masterNode.emitOnRadio(new RadioEvent(this.masterNode, this.birdTableNode, new FeedCommand()))
        this.delay(5000, sendEvent)
    }

    private getData(): uint8_t[] {
        let data: uint8_t[] = []
        for(let i = 0; i < 10; i++) {
            data.push(new uint8_t(i))
        }
        return data
    }

    private runWifiSimulation() {
        let home: NetworkNode = {
            ID: new uint8_t(255)
        }
        this.wifiNet.emit(new WifiEvent(home, this.doorNode, [new CloseCommand()]))
    }

    private delay(millis: number, next) {
        setTimeout(() => {
            next()
        }, millis);
    }
}

new Main([])