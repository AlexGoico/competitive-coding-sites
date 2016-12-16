import Control.Applicative

solve :: Int -> Int -> Int
solve m n = (m * n) `div` 2

main :: IO ()
main = do
  [m, n] <- fmap read . words <$> getLine :: IO [Int]
  putStrLn $ show $ solve m n
