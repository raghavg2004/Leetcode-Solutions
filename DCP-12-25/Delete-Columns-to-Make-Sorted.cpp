1namespace stdv = std::views;
2namespace stdr = std::ranges;
3
4class Solution
5{
6public:
7    auto minDeletionSize(std::vector<std::string>& strs)
8    {
9        auto& map = stdv::transform;
10        return stdr::count(
11            stdv::iota(0uz, strs[0].size()) |
12                map([&](size_t x)
13                    { return strs | map([&, x](auto& s) { return s[x]; }); }) |
14                map(stdr::is_sorted),
15            false);
16    }
17};