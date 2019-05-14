import { Emitter } from "./emitter";
import { RadioReceiver } from "../receiver/radio-receiver";

export abstract class RadioEmitter implements Emitter {
    listen: (listener: RadioReceiver) => void
    emit: () => void
}