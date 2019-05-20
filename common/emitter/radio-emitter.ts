import { Emitter } from "./emitter";
import { RadioReceiver } from "../receiver/radio-receiver";

export abstract class RadioEmitter implements Emitter {
    abstract subscribe: (listener: RadioReceiver) => void
    abstract emit: () => void
}