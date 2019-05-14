import { NetworkEvent } from "./network-event";
import { NetworkNode } from "../node/network-node";

export class WifiEvent implements NetworkEvent {
    emitter: NetworkNode
    msg: string;

}