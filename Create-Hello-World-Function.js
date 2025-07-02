/**
 * @return {Function}
 */
var createHelloWorld = function() {
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 * f(1, 2, 3); // "Hello World"
 * f({}, null); // "Hello World"
 */
