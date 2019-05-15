import { Emitter } from "./emitter";
import { RadioReceiver } from "../receiver/radio-receiver";
import { NetworkNode } from "../node/network-node";

export abstract class RadioEmitter implements Emitter {
    listen: (listener: RadioReceiver) => void
    emit: () => void
}