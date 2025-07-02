/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timeoutId;

    return function(...args) {
        // Clear the previously scheduled call
        if (timeoutId) clearTimeout(timeoutId);

        // Schedule a new call after `t` ms
        timeoutId = setTimeout(() => {
            fn(...args);
        }, t);
    };
};
