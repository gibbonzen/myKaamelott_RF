import { NetworkNode } from "../node/network-node";

export interface NetworkEvent {
    emitter: NetworkNode
    msg: string
}