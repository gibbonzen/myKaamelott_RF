"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class OtherTools {
    static delay(millis, next) {
        setTimeout(() => {
            next();
        }, millis);
    }
}
exports.OtherTools = OtherTools;
//# sourceMappingURL=other-tools.js.map