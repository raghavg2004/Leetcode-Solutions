/**
 * @param {Function} fn
 * @param {number} t - time limit in ms
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    return async function(...args) {
        return new Promise((resolve, reject) => {
            // Timeout that rejects after t milliseconds
            const timeoutId = setTimeout(() => {
                reject("Time Limit Exceeded");
            }, t);

            // Try to run fn(...args)
            fn(...args)
                .then((res) => {
                    clearTimeout(timeoutId); // Clear the timer if fn resolves in time
                    resolve(res);
                })
                .catch((err) => {
                    clearTimeout(timeoutId); // Clear the timer if fn rejects in time
                    reject(err);
                });
        });
    };
};
