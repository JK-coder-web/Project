import { createContext, useState } from "react";

export const FirstContext = createContext(null);

const FirstContextProvider = (props) => {
  const userName = "codehub myanmar";
  const liveIn = "YGN";

  const [num, setNum] = useState(0);

  return (
    <FirstContext.Provider value={{ userName, liveIn, num, setNum }}>
      {props.children}
    </FirstContext.Provider>
  );
};

export default FirstContextProvider;
