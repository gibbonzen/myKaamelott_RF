import { Command } from "../node/command";

export interface CommandRunner {
    isRunnable(command: Command): boolean
    run(command: Command): void
}