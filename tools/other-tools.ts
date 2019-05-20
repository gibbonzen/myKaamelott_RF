export class OtherTools {
    static delay(millis: number, next) {
        setTimeout(() => {
            next()
        }, millis);
    }
}