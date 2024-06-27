import { useContext } from "react";
import { FirstContext } from "../FirstContext";

const Child3 = () => {
  const { userName, liveIn } = useContext(FirstContext);
  return (
    <>
      <div>Child3</div>
      <div>
        from child 3 <br />
        {userName}
        {liveIn}
      </div>
    </>
  );
};

export default Child3;
