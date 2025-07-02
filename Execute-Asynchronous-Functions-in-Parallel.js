/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const results = [];
        let completed = 0;
        const total = functions.length;

        functions.forEach((fn, i) => {
            try {
                fn()
                    .then((res) => {
                        results[i] = res;
                        completed++;
                        if (completed === total) {
                            resolve(results);
                        }
                    })
                    .catch(reject); // Reject immediately on first failure
            } catch (err) {
                reject(err); // Catch synchronous errors in fn()
            }
        });
    });
};
