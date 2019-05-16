"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const feed_command_1 = require("./feed-command");
const radio_command_1 = require("../common/node/radio-command");
class BirdTableCommandFactory {
    create(data) {
        switch (data.command.ID.valueOf()) {
            case radio_command_1.RadioCommands.FEED:
                return new feed_command_1.FeedCommand();
            default:
                return undefined;
        }
    }
}
exports.BirdTableCommandFactory = BirdTableCommandFactory;
//# sourceMappingURL=bird-table-command-factory.js.map