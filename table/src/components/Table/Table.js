import React, { useState, useEffect } from 'react';
import {initialData} from '../../data/data';
import "./Table.css"

function Table({}) {

    const [up, setUp] = useState(true);
    const [count, setCount] = useState(16);
    const [checkbox, setCheckbox] = useState([]);
    const [isSorted, setIsSorted] = useState([]);
    const [data, setData] = useState(initialData.data);
    const [display, setDisplay] = useState("display-none");
    const [allIsChecked, setAllIsChecked] = useState(false);


    const isChecked = function(element) {
        if(element == true) {
            return true;
        }

        return false;
    }

    const sortUp = function(sortData, dataIndex) {
        for(let i = 0; i < sortData.length; ++i) {
            for(let j = 0 ; j < sortData.length; ++j) {
                if(sortData[i].[dataIndex] < sortData[j].[dataIndex]) {
                    let tmp = sortData[i];
                    sortData[i] = sortData[j];
                    sortData[j] = tmp;
                }
            }
        }

        return sortData;
    }

    const sortDown = function(sortData, dataIndex) {
        for(let i = 0; i < sortData.length; ++i) {
            for(let j = 0 ; j < sortData.length; ++j) {
                if(sortData[i].[dataIndex] > sortData[j].[dataIndex]) {
                    let tmp = sortData[i];
                    sortData[i] = sortData[j];
                    sortData[j] = tmp;
                }
            }
        }

        return sortData;
    }

    const sort = function(dataIndex, index) {
        const sortData = [...data];
        const sorted = [...isSorted];

        if(up) {
            sorted[index] = "down";
            setUp(false);
            setIsSorted(sorted);
            setData(sortUp(sortData, dataIndex));
        } else {

            sorted[index] = "up";
            setUp(true);
            setIsSorted(sorted);
            setData(sortDown(sortData, dataIndex));
        }
    }


    const selectAll = function() {
        if(checkbox.find(isChecked)) {
            const checkbox = [];

            for(let i = 0; i < count; ++i) {
                checkbox[i] = false;
            }

            setCheckbox(checkbox);
            setAllIsChecked(false);
            setDisplay("display-none");

        } else {
            const checkbox = [];

            for(let i = 0; i < count; ++i) {
                checkbox[i] = true;
            }

            setCheckbox(checkbox);
            setAllIsChecked(true);
            setDisplay("display-unset");
        }

    }

    const selectOne = function (index) {
        let tmp = [...checkbox];
        tmp[index] = !tmp[index];
        setCheckbox(tmp);

        if(allIsChecked) {
            setAllIsChecked(false);
        }

        if(tmp.find(isChecked)) {
            setDisplay("display-unset");
        } else {
            setDisplay("display-none");
        }

    }

    const removeItems = function() {
        const newData = [...data];
        const newCheckbox = [...checkbox];

        for(let i = count - 1; i >= 0; --i) {
            if(checkbox[i]) {
                newData.splice(i, 1);
                newCheckbox.splice(i, 1);
            }

        }

        setData(newData);
        setAllIsChecked(false);
        setCheckbox(newCheckbox);
        setDisplay("display-none");
    }

    useEffect(() => {
        function userInfo() {
            const checkbox = [];
            const sorted = [];
            for(let i = 0; i < data.length; ++i) {
                checkbox.push(false)
            }
            for(let i = 0; i < initialData.headers.length; ++i) {
                if(initialData.headers[i].sorter) {
                    sorted.push("up");
                } else {
                    sorted.push(false);
                }
            }
            setCheckbox(checkbox);
            setIsSorted(sorted)
        }

        userInfo();
    }, []);


    window.onscroll = function(ev) {
        if ((window.innerHeight + window.scrollY) >= document.body.offsetHeight) {
            setCount(count + 2);
        }
    };

    return (
        <div>
            <div className="mt-50 ">
                <button className={`remove fixed ${display}`} onClick={removeItems}>Remove Selected Items</button>
                <table id="customers" className="w-75">
                    <thead className="">
                        <tr>
                            <th>
                                <input type="checkbox" onClick={selectAll} checked={allIsChecked || false} readOnly/>
                            </th>
                            <th> N </th>
                            { initialData.headers && initialData.headers.map((header, index) => {
                                return (
                                    <th key={index.toString()} style={{'width': `${header.width}px`}} onClick={() => sort(header.dataIndex, index)}>{header.title} {header.sorter ? (isSorted[index] == "up" ?  <>▲</> :  <>▼</>) : null}</th>
                                )
                            })}

                        </tr>
                    </thead>
                    <tbody>
                        { data && data.map((item, index) => {
                            if(index < count) {
                            return (
                                <tr id={`row${index}`} onClick={() => selectOne(index)} key={index.toString()}>
                                    <td><input type="checkbox" checked={checkbox[index] || false} readOnly /></td>
                                    <td>{index + 1}</td>
                                    <>
                                        {Object.keys(item).map(function(key, i) {
                                            return <td key={i.toString()}>{item[key]}</td>
                                        })}
                                    </>
                                </tr>
                            )
}                       })}
                    </tbody>
                </table>
            </div>
        </div>
    );
}

export default Table;
