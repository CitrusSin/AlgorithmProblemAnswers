
split :: Eq a => a -> [a] -> [[a]]
split d [] = [[]]
split d (h:hs)
    | d == h    = [] : split d hs
    | otherwise = appendLast h (split d hs)
        where appendLast h (x : xs) = (h : x) : xs

main :: IO ()
main = do
    x <- getLine
    print $ split ' ' x