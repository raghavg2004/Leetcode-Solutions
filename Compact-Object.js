/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (Array.isArray(obj)) {
        return obj
            .map(compactObject)        // Recursively process items
            .filter(Boolean);          // Remove falsy items
    } else if (obj !== null && typeof obj === 'object') {
        const result = {};
        for (const key in obj) {
            const value = compactObject(obj[key]);  // Recurse
            if (Boolean(value)) {
                result[key] = value;
            }
        }
        return result;
    } else {
        return obj;
    }
};
