/**
 * @param {number[]} nums
 * @return {void}
 */
var ArrayWrapper = function(nums) {
    this.arr = nums;
};

/**
 * @return {number}
 * Used when object is involved in arithmetic like + or -
 */
ArrayWrapper.prototype.valueOf = function() {
    return this.arr.reduce((sum, num) => sum + num, 0);
};

/**
 * @return {string}
 * Used in String(obj) or obj.toString()
 */
ArrayWrapper.prototype.toString = function() {
    return `[${this.arr.join(",")}]`;
};
