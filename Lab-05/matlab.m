% Initialize variables
s = 4; % Skill level
target_coins = 1000; % Target number of coins
c = 0; % Initialize cl
l = 1; % Initialize level

while c < target_coins
    % Generate a random number of hits between 1 and l * s
    hits = randi([1, l * s]);
    
    % Calculate coins collected and update c
    c = c + 10 - 3 * hits;
    l = l + 1;
end

fprintf('Number of levels needed to reach %d coins at skill level %d (random hits): %d\n', target_coins, s, l-1);
