/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function(arr, depth) {
    const result = [];

    const helper = (arr, currentDepth) => {
        for (const item of arr) {
            if (Array.isArray(item) && currentDepth < depth) {
                helper(item, currentDepth + 1);
            } else {
                result.push(item);
            }
        }
    };

    helper(arr, 0);
    return result;
};
