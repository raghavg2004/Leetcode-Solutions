var TimeLimitedCache = function() {
    this.cache = new Map();  // key -> { value, expireTime }
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration - time in ms
 * @return {boolean} - true if unexpired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const currentTime = Date.now();
    const expireAt = currentTime + duration;

    const exists = this.cache.has(key);
    const isUnexpired = exists && this.cache.get(key).expire > currentTime;

    // Always set new value and expiration time
    this.cache.set(key, {
        value: value,
        expire: expireAt
    });

    return isUnexpired;
};

/** 
 * @param {number} key
 * @return {number} value if key exists and is unexpired, otherwise -1
 */
TimeLimitedCache.prototype.get = function(key) {
    const currentTime = Date.now();
    if (!this.cache.has(key)) return -1;

    const entry = this.cache.get(key);
    if (entry.expire > currentTime) {
        return entry.value;
    } else {
        this.cache.delete(key);
        return -1;
    }
};

/** 
 * @return {number} count of unexpired keys
 */
TimeLimitedCache.prototype.count = function() {
    const currentTime = Date.now();
    let count = 0;
    for (const [key, entry] of this.cache) {
        if (entry.expire > currentTime) {
            count++;
        } else {
            this.cache.delete(key); // Clean up expired entries
        }
    }
    return count;
};
