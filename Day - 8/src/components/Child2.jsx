import { useContext } from "react";
import { FirstContext } from "../FirstContext";

const Child2 = () => {
  const { num, setNum } = useContext(FirstContext);
  return (
    <>
      <div>Child2</div>
      <div>{num}</div>
      <button onClick={() => setNum((prev) => prev + 1)}>+1</button>
    </>
  );
};

export default Child2;
