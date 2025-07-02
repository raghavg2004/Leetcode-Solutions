/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    return args.length;
};

/**
 * Example Usage:
 * argumentsLength(1, 2, 3); // 3
 * argumentsLength(); // 0
 * argumentsLength(null, {}, "hello"); // 3
 */
