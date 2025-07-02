/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    // Call the function immediately
    fn(...args);

    // Set interval to keep calling fn
    const intervalId = setInterval(() => {
        fn(...args);
    }, t);

    // Return the cancel function to clear the interval
    return function cancelFn() {
        clearInterval(intervalId);
    };
};
