"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class Logger {
    static log(msg, clazz, color = Color.FG_DEFAULT) {
        if (clazz)
            msg = `[${this.getObjectClass(clazz)}]: ${msg}`;
        this.print(msg, color);
    }
    static print(msg, color) {
        console.log(`${color}%s${Color.RESET}`, msg);
    }
    static getObjectClass(obj) {
        let objToStr = obj.toString();
        let isClazzObject = /class ([a-zA-Z]*) {.*/gi.exec(objToStr);
        if (isClazzObject !== null && [1] !== null)
            return isClazzObject[1];
        let isInstanceOf = /class ([a-zA-Z]*)/gi.exec(obj.constructor.toString());
        if (isInstanceOf !== null && [1] !== null)
            return isInstanceOf[1];
        return undefined;
    }
}
exports.Logger = Logger;
var Color;
(function (Color) {
    Color["RESET"] = "\u001B[0m";
    Color["BRIGHT"] = "\u001B[1m";
    Color["DIM"] = "\u001B[2m";
    Color["UNDERSCORE"] = "\u001B[4m";
    Color["BLINK"] = "\u001B[5m";
    Color["REVERSE"] = "\u001B[7m";
    Color["HIDDEN"] = "\u001B[8m";
    // Normal colors
    Color["FG_DEFAULT"] = "\u001B[39m";
    Color["FG_BLACK"] = "\u001B[30m";
    Color["FG_RED"] = "\u001B[31m";
    Color["FG_GREEN"] = "\u001B[32m";
    Color["FG_YELLOW"] = "\u001B[33m";
    Color["FG_BLUE"] = "\u001B[34m";
    Color["FG_MAGENTA"] = "\u001B[35m";
    Color["FG_CYAN"] = "\u001B[36m";
    Color["FG_WHITE"] = "\u001B[97m";
    Color["FG_GRAY"] = "\u001B[90m";
    // Light colors
    Color["FG_GRAY_LIGHT"] = "\u001B[37m";
    Color["FG_RED_LIGHT"] = "\u001B[91m";
    Color["FG_GREEN_LIGHT"] = "\u001B[92m";
    Color["FG_YELLOW_LIGHT"] = "\u001B[93m";
    Color["FG_BLUE_LIGHT"] = "\u001B[94m";
    Color["FG_MAGENTA_LIGHT"] = "\u001B[95m";
    Color["FG_CYAN_LIGHT"] = "\u001B[96m";
    // Normal
    Color["BG_DEFAULT"] = "\u001B[49m";
    Color["BG_BLACK"] = "\u001B[40m";
    Color["BG_RED"] = "\u001B[41m";
    Color["BG_GREEN"] = "\u001B[42m";
    Color["BG_YELLOW"] = "\u001B[43m";
    Color["BG_BLUE"] = "\u001B[44m";
    Color["BG_MAGENTA"] = "\u001B[45m";
    Color["BG_CYAN"] = "\u001B[46m";
    Color["BG_WHITE"] = "\u001B[107m";
    Color["BG_GRAY"] = "\u001B[100m";
    // Light
    Color["BG_GRAY_LIGHT"] = "\u001B[47m";
    Color["BG_RED_LIGHT"] = "\u001B[101m";
    Color["BG_GREEN_LIGHT"] = "\u001B[102m";
    Color["BG_YELLOW_LIGHT"] = "\u001B[103m";
    Color["BG_BLUE_LIGHT"] = "\u001B[104m";
    Color["BG_MAGENTA_LIGHT"] = "\u001B[105m";
    Color["BG_CYAN_LIGHT"] = "\u001B[106m";
})(Color = exports.Color || (exports.Color = {}));
//# sourceMappingURL=logger.js.map