class EventEmitter {
    constructor() {
        this.events = new Map(); // Map of eventName -> array of listeners
    }

    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        if (!this.events.has(eventName)) {
            this.events.set(eventName, []);
        }

        const listeners = this.events.get(eventName);
        listeners.push(callback);

        // Store index of this subscription for unsubscribing
        const index = listeners.length - 1;

        return {
            unsubscribe: () => {
                // Mark the callback as null (preserves order)
                listeners[index] = null;
            }
        };
    }

    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        if (!this.events.has(eventName)) {
            return [];
        }

        const listeners = this.events.get(eventName);
        const results = [];

        for (const callback of listeners) {
            if (callback !== null) {
                results.push(callback(...args));
            }
        }

        return results;
    }
}
