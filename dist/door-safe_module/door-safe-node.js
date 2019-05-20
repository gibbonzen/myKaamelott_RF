"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const radio_emitter_1 = require("../common/emitter/radio-emitter");
const uint8_t_1 = require("../tools/uint8_t");
class DoorSafeNode extends radio_emitter_1.RadioEmitter {
    constructor(ID) {
        super();
        this.ID = new uint8_t_1.uint8_t(ID);
    }
}
exports.DoorSafeNode = DoorSafeNode;
//# sourceMappingURL=door-safe-node.js.map